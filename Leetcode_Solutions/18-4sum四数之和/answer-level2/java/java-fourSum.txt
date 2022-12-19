### 解题思路
- 最大值和最小值比较可以很大程度上提高时间。
- 排序帮助去重复。

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
      if (nums.length<4 || nums==null){
            return Collections.emptyList();
        }
        List<List<Integer>> lists = new ArrayList<>();
        Arrays.sort(nums);
        int min=0,max=0;
        for (int i=0;i<nums.length-3;i++){
            //重复，跳过
            if (i>=1&&nums[i]==nums[i-1]){
                continue;
            }
            //与最小值比较
            min=nums[i]+nums[i+1]+nums[i+2]+nums[i+3];
            //与最大值比较
            max=nums[nums.length-1]+nums[nums.length-2]+nums[nums.length-3]+nums[nums.length-4];
            if (target>max || target<min){
                return lists;
            }
            for (int j=i+1;j<nums.length-2;j++){
                int l=j+1,r=nums.length-1;
                //重复，跳过
                if ((j!=i+1)&&nums[j]==nums[j-1]){
                    continue;
                }
                //与最小值比较
                min=nums[i]+nums[j]+nums[j+1]+nums[j+2];
                if (target<min){
                    break;
                }
                //与当前最大值比较
                max=nums[i]+nums[j]+nums[r-1]+nums[r];
                if (target>max){
                    continue;
                }
                while(l<r){
                    int curr=nums[i]+nums[j]+nums[l]+nums[r];
                    if (curr==target){
                        //list是有序的，注意四个元素书写顺序
                        List<Integer> list= Arrays.asList(nums[i],nums[j],nums[l],nums[r]);
                        lists.add(list);
                        l++;
                        r--;
                        //四个数已经有两个确定了如果num[l]或num[r]其中某一个跟刚才的一样，就一定会重复。
                        while (l<r&&nums[l]==nums[l-1]){
                                l++;
                        }
                        while (l<r&&nums[r]==nums[r+1]){
                                r--;
                        }
                    }else if (curr>target){
                        r--;
                    }else{
                        l++;
                    }
                }
            }
        }
        return lists;
    }
}
```