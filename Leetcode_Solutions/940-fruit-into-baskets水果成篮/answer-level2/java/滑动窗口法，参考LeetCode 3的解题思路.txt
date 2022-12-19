### 解题思路
LeetCode 3求的是无重复字符的最长子串，maxLen = index-start+1，关键点在于何时更新子串的起点 start，该题核心思路是：
找出重复的字符——找出重复字符上一次出现的位置pos——排除重复字符，设置start为pos+1

相应地，本题相当于找出第三个数字，即多余的数字，maxLen = index-start+1，关键点在于何时更新子数组的起点，核心思路是：
出现第三个数字后——找出原有两个数字最新出现的位置pos1,pos2——排除掉较旧的数字，设置start为min(pos1,pos2)+1

T(n) = O(n)
S(n) = O(1)

### 代码

```java
class Solution {
    public int totalFruit(int[] tree) {
        //coner case
        if(tree == null || tree.length == 0) return 0;

        //初始化两个数字，选择两个篮子的水果
        int maxLen = 0;
        int start = 0;//记录子数组的起始位置
        int index = 0;
        int[] first = new int[] {tree[0], 0};
        int[] second = new int[2];
        while(index < tree.length){
            if(tree[index]!=first[0]) break;
            first[1] = index;
            index++;
        }
        if(index < tree.length){
            second[0] = tree[index];
            second[1] = index;
            maxLen = index-start+1;
        }else{
            //coner case
            return tree.length;//return index;
        }

        //滑动窗口的右侧遍历数组，不断更新start
        for(int i = index+1; i < tree.length; i++){
            if(tree[i] == first[0]){
                first[1] = i;
            }else if(tree[i] == second[0]){
                second[1] = i;
            }else{
                //更新数字，同时更新start
                start = Math.min(first[1], second[1])+1;//关键代码，排除旧数字，排除旧水果
                if(first[1] < second[1]){
                    first[0] = tree[i];
                    first[1] = i;
                }else{
                    second[0] = tree[i];
                    second[1] = i;
                }
            }
            //更新maxLen
            maxLen = Math.max(maxLen, i-start+1);
        }
        return maxLen;
    }
}
```