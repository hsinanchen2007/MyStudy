### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;

        for(int i=0;i<n;i++)
        {
            List<Integer> temp = new ArrayList<>();
            temp.add(nums[i]);
            fun(nums,n,result,temp);
        }
        return result;
    }

    public void fun(int[] nums,int n,List<List<Integer>> result,List<Integer> temp)
    {
        if(temp.size()==n)
        {
            List<Integer> temp1 = new ArrayList<>(temp);
            // for(int j=0;j<n;j++)
            // {
            //     temp1.add(temp.get(j));
            // }
            result.add(temp1);
        }
        else
        {
            for(int k=0;k<n;k++)
            {
                if(!temp.contains(nums[k]))
                {
                    temp.add(nums[k]);
                    fun(nums,n,result,temp);
                    temp.remove(temp.size()-1);
                }
            }
        }
    }
}
```