### 解题思路
1. 用char型数组存储二进制位
2. 添加进List里的十进制数记得用visited数组标记，避免重复添加。
3. 将char型数组的某位变动后，若当前计算出的数值已经被List添加过，记得“恢复”

### 代码

```java
class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<>();
        res.add(0);
        if (n == 0){
            return res;
        }
        char[] basic = new char[n];
        int num = (int)Math.pow(2, n);
        int[] visited = new int[num];
        visited[0] = 1;
        Arrays.fill(basic,'0');
        dfs(basic, 0, res, num, visited);
        return res;
    }


    private void dfs(char[] basic, int i, List<Integer> res, int num, int[] visited){
        if (res.size() == num)
            return ;
        //改变basic[i]对应的位置的值
        basic[i] = (basic[i] == '1')?'0':'1';
        int val = calCharArray(basic);
        if (visited[val] == 0){
            visited[val] = 1;
            res.add(val);
        }
        else{
            basic[i] = (basic[i] == '1')?'0':'1';
            return;
        }
        for(int j = 0;j < basic.length;j++){
            if (j != i){
                dfs(basic, j, res, num, visited);
            }
        }
    }

    private int calCharArray(char[] chars){
        int sum = 0;
        for (int i = 0; i < chars.length; i++) {
            sum = sum * 2 + (chars[i] - '0');
        }
        return sum;
    }
}
```