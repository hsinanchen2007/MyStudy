#### 一、题目分析
- 本题使用 DFS 求解，有 TLE 的可能
- 本题应使用贪心算法，大致思路为：
    - 若 $colsum[i]=2$，则 **一定上下均为 1**
    - 若 $colsum[i]=0$，则 **一定上下均为 0**
    - 若 $colsum[i]=1$，则 **上下一个 1 一个 0**
    - **唯一需要讨论的只有 $colsum[i]=1$ 的情形，我们可以规定：先分配上为 1，再分配下为 1**
- 无解的情形与解决方案：
    - 行元素之和（$upper+lower$）与列元素之和（$\sum colsum$）不相等
        - 解决方案：一次循环，求出 $\sum colsum$，与 $upper+lower$ 比较
    - 行元素之和不够
        - 解决方案 1：排除所有 $0$ 的项与 $2$ 的项，观察此时 $upper$ 与 $lower$ 是否为负值
        - 解决方案 2：直接分配，分配完成后，观察此时 $upper$ 与 $lower$ 是否为负值

下面通过一个例子简单说明。

#### 二、例子
- **例 1**：$upper = 2, lower = 3, colsum = [2,2,1,1]$
    - 分析：
        - $upper+lower=5$，$\sum colsum=6$，**两者不相等**，故无解
    - 答案：$[]$
- **例 2**：$upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]$
    - 分析：
        - $upper+lower=10$，$\sum colsum=10$，故可能有解
        - 所有 $0$ 与 $2$ 的项排除掉，此时 $upper = 2, lower = 2, colsum = [1,1,1,1]$
        - $upper, lower$ 均大于 $0$，故一定有解。将 $colsum$ 的前两个 $1$ 用 $upper$，后两个 $1$ 用 $lower$ 即可
    - 答案：$[[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]$
- **例 3**：$upper = 9, lower = 2, colsum = [0,1,2,0,0,0,0,0,2,1,2,1,2]$
    - 分析：
        - $upper+lower=11$，$\sum colsum=11$，故可能有解
        - 所有 $0$ 与 $2$ 的项排除掉，此时 $upper = 5, lower = -2, colsum = [1,1,1]$
        - $lower<0$，说明 $lower$ 不够分配，故无解
    - 答案：$[]$

#### 三、Coding
解决方案1的代码：
```java [-Java]
public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
    // up记录第0行可分配的1个数，lo记录第1行可分配的1个数
    int up = upper, lo = lower, sum = 0, len = colsum.length;
    List<List<Integer>> list = new ArrayList<>();
    for(int i = 0; i < len; i ++){
        if(colsum[i] == 2){
            up --;
            lo --;
        }
        else if(colsum[i] == 1){
            sum++;
        }
    }
    // 如果行列元素之和不相等，或行元素之和不够分配
    if(up + lo != sum || up < 0 || lo < 0){
        return list;
    }
    List<Integer> upl = new ArrayList<>();
    List<Integer> lol = new ArrayList<>();
    for(int i = 0; i < len; i ++){
        if(colsum[i] == 2){
            upl.add(1);
            lol.add(1);
        }
        else if(colsum[i] == 0){
            upl.add(0);
            lol.add(0);
        }
        else {
            // 先分配上
            if(up-- > 0){
                upl.add(1);
                lol.add(0);
            }
            // 再分配下
            else {
                lol.add(1);
                upl.add(0);
            }
        }
    }
    list.add(upl);
    list.add(lol);
    return list;
}
```
解决方案2的代码：
```java [-Java]
public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
    int sum = 0, len = colsum.length;
    List<List<Integer>> list = new ArrayList<>();
    for(int i = 0; i < len; i ++){
        sum += colsum[i];
    }
    // 如果行列元素之和不相等
    if(upper + lower != sum){
        return list;
    }
    List<Integer> upl = new ArrayList<>();
    List<Integer> lol = new ArrayList<>();
    for(int i = 0; i < len; i ++){
        if(colsum[i] == 2){
            upl.add(1);
            lol.add(1);
            upper --;
            lower --;
        }
        else if(colsum[i] == 0){
            upl.add(0);
            lol.add(0);
        }
        else {
            if(upper > lower){
                upl.add(1);
                lol.add(0);
                upper --;
            }
            else {
                lol.add(1);
                upl.add(0);
                lower --;
            }
        }
        // 如果行元素不够分配
        if(upper < 0 || lower < 0){
            return list;
        }
    }
    list.add(upl);
    list.add(lol);
    return list;
}
```
时间复杂度：$O(n)$，空间复杂度：$O(n)$