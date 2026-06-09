### 解题思路
利用一个temp存储子序列，若nums[i+1]==nums[i]+1，则属于一个子序列。最后加上一个判断条件判断是否需要加“->”即可。
### 代码

```java
class Solution {
    public List<String> summaryRanges(int[] nums) {//一次AC的感觉真滴爽
        List<String> ans = new ArrayList<>(); 
        if(nums.length==0)
         return ans;
        for(int i=0;i<nums.length;i++)
        {
            StringBuffer temp = new StringBuffer();//当前字符串
            int pre=nums[i];
            temp.append(pre);//子序列开头字符
            while(i+1<nums.length&&nums[i+1]==nums[i]+1)//找到子序列结尾
            i++;
            if(pre!=nums[i])//若子序列不是一个数，则加上“->”和末尾数字
            {
             temp.append("->");
             temp.append(nums[i]);
            }
            ans.add(temp.toString());//加入答案列表
        }
        return ans;
    }
}
```