__________________________________________________________________

 大概思路就是双重循环固定两个数，最里面用双指针。复杂度为`n^3`，不是很好。

执行用时 :
125 ms
, 在所有 Java 提交中击败了
13.59%
的用户
内存消耗 :
37.6 MB
, 在所有 Java 提交中击败了
93.56%
的用户

__________________________________________________________________

需要注意的是，i 、j 、 left 、right四个指针不能一次只加一，要放在循环里面判断。
如果当前的数和下一个数是一样的，那么下一个数的加和情况已经包含在当前加和的
情况里面了。这样做可以防止重复情况，还能处理{0，0，0，...，0，0，0}这种刁钻情况。

________________________________________________________________
```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer > > ans = new ArrayList<List<Integer > >();
        Arrays.sort(nums);
        for(int i = 0 ; i < nums.length - 3 ;){
            for(int j = i + 1 ; j < nums.length - 2 ;){
                int left = j + 1, right = nums.length - 1;
                while(left < right){
                    int k = nums[i] + nums[j] + nums[left] + nums[right];
                    if(k == target){
                        List<Integer> ans_ = new ArrayList<Integer >();
                        ans_.add(nums[i]); ans_.add(nums[j]);
                        ans_.add(nums[left]); ans_.add(nums[right]);
                        ans.add(ans_);
                        do{
                            ++left;
                        }while(left < right && nums[left] == nums[left - 1]);
                         do{
                            --right;
                        }while(left < right && nums[right] == nums[right + 1]);
                    }
                    else if(k < target){
                        do{
                            ++left;
                        }while(left < right && nums[left] == nums[left - 1]);
                    }
                    else{
                         do{
                            --right;
                        }while(left < right && nums[right] == nums[right + 1]);
                    }
                }
                do{
                    ++j;
                }while(j < nums.length - 2 && nums[j] == nums[j - 1]);
            }
            do{
                ++i;
            }while(i < nums.length - 3 && nums[i] == nums[i - 1]);
        }
        return ans;
    }
}
```



______________________________________________________________________
# 更新

找到我程序慢的关键了，忘剪枝了(●'◡'●)

______________________________________________________________________
执行用时 :
8 ms
, 在所有 Java 提交中击败了
99.10%
的用户
内存消耗 :
35.6 MB
, 在所有 Java 提交中击败了
99.83%
的用户



程序没变，就加入了4条剪枝语句。
当(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3])大于target时，循环结束。因为数组是有序排列的，
当三个最小的数加nums[i]都大于target，越往后只会越来越大而不会减小。

当(nums[i] + nums[nums.length - 1] + nums[nums.length - 2] + nums[nums.length - 3])小于target时，
三个最大的数加nuns[i]都小于target，说明nums[i]太小了，应该提前结束这一次循环。

```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer > > ans = new ArrayList<List<Integer > >();
        Arrays.sort(nums);
        for(int i = 0 ; i < nums.length - 3 ;){
            //剪枝
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break; 
            if(nums[i] + nums[nums.length - 1] + nums[nums.length - 2] + nums[nums.length - 3] < target){
                ++i;
                continue;
            }
            //end
            for(int j = i + 1 ; j < nums.length - 2 ;){
                int left = j + 1, right = nums.length - 1;
                 //剪枝
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if(nums[i] + nums[nums.length - 1] + nums[nums.length - 2] + nums[j] < target){
                    ++j;
                    continue;
                }
                //end
                while(left < right){
                    int k = nums[i] + nums[j] + nums[left] + nums[right];
                    if(k == target){
                        List<Integer> ans_ = new ArrayList<Integer >();
                        ans_.add(nums[i]); ans_.add(nums[j]);
                        ans_.add(nums[left]); ans_.add(nums[right]);
                        ans.add(ans_);
                        do{
                            ++left;
                        }while(left < right && nums[left] == nums[left - 1]);
                         do{
                            --right;
                        }while(left < right && nums[right] == nums[right + 1]);
                    }
                    else if(k < target){
                        do{
                            ++left;
                        }while(left < right && nums[left] == nums[left - 1]);
                    }
                    else{
                         do{
                            --right;
                        }while(left < right && nums[right] == nums[right + 1]);
                    }
                }
                do{
                    ++j;
                }while(j < nums.length - 2 && nums[j] == nums[j - 1]);
            }
            do{
                ++i;
            }while(i < nums.length - 3 && nums[i] == nums[i - 1]);
        }
        return ans;
    }
}
```

