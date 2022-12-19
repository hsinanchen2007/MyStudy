### 解题思路
LeetCode003的关键技巧是：使用Hash记录每种字符最近出现的位置。右指针向右移动，每次遇到字符就判断是否重复出现，如果上一次出现的位置lastPos在左子针右侧，截取字符串，把做左子针调到lastPos
LeetCode904同样应用这个技巧。但是只需要记录两个字符最近出现位置 lastPosA lastPosB。这里的代码在逻辑上要做一些变动：当出现第三个字符时，需要更新掉min(lastPosA, lastPosB)，因为它对应的字符不能算了
比如,right指针移到下述数字3的位置时：
```
         |(r)
1112112223333
     |  | 
```
肯定是把左侧所有的1都排除掉，重新计算


### 代码

```java
class Solution {
    public int totalFruit(int[] tree) {
        //题目可以理解为包含两种字符的最长子串
        //题目可以理解为无重复字符的最长子串
        //coner case
        if(tree == null || tree.length == 0) return 0;

        //初始化，选择两个篮子的水果
        int maxLen = 0;
        int start = 0;//记录子数组的起始位置
        int index = 0;
        int[] first = new int[] {tree[0], 0};//first[0]是水果，first[1]是lastPos
        int[] second = new int[2];
        while(index < tree.length){
            if(tree[index]!=first[0]) break;
            first[1] = index;
            index++;
        }
        //初始化可能遇到的边界情况：只有一种水果
        if(index < tree.length){
            second[0] = tree[index];
            second[1] = index;
            maxLen = index-start+1;
        }else{
            return tree.length;//return index;
        }

        

        for(int i = index+1; i < tree.length; i++){
            //更新水果最新出现的位置
            if(tree[i] == first[0]){
                first[1] = i;
            }else if(tree[i] == second[0]){
                second[1] = i;
            }else{
                //更新篮子放的水果类型，同时更新start
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