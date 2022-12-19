简单哈希表，要注意数组开始的索引为零！
```
    class Solution {
        public int[] findErrorNums(int[] nums) {
            int res[] =new int[2];
            int count[] =new int[10001];
            for(int i=0; i < nums.length; i++)
            {
                count[nums[i]-1]++;//哈希表count的索引注意从0开始。
            }
            
            for(int i=0;i<nums.length;i++)
            {
                if(count[i]==2)
                {
                    res[0] = i+1;//某一个值找到了两次，加一是因为count[i]里面的i是被减过1之后的i。
                }
                if(count[i]==0)
                {
                    res[1] = i+1;
                }
            }
            return res;
        }
    }
```
![无标题.png](https://pic.leetcode-cn.com/ff79fe6494b63cf5890198aa19190f81214c369c4f219d47765dc7543d0e6494-%E6%97%A0%E6%A0%87%E9%A2%98.png)