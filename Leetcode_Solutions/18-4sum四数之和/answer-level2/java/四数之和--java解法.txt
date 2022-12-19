### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> lists = new ArrayList<>();
        List<Integer> list;
        int len = nums.length;
        if(len<4){
            return lists;
        }
        Arrays.sort(nums);
        for(int i=0;i<len-3;i++){
            for(int j=i+1;j<len-2;j++){
                int L=j+1;
                int R=len-1;
                while (L<R){
                    int ans = nums[i]+nums[j]+nums[L]+nums[R];
                    while (ans<target){
                        L++;
                        if(L>=R){
                            break;
                        }
                        else if(nums[L]==nums[L-1]){
                            continue;
                        }
                        ans = nums[i]+nums[j]+nums[L]+nums[R];
                    }
                    while (ans>target){
                        R--;
                        if(L>=R){
                            break;
                        }
                        else if(nums[R]==nums[R+1]){
                            continue;
                        }
                        ans = nums[i]+nums[j]+nums[L]+nums[R];
                    }
                    if (ans==target){
                        list = new ArrayList<>();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[L]);
                        list.add(nums[R]);
                        if(lists.contains(list)){
                            L++;
                            R--;
                            continue;
                        }
                        lists.add(list);
                        L++;
                        R--;
                    }
                }
            }
        }
        return lists;
    }
}
```