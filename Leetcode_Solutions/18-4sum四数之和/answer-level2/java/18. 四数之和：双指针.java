### 解题思路
其实大致思路跟三数之和差不多，只是多了一层循环；
先把给定数组排序，之后需要先确定两个数的值，接下来在利用双指针，遍历所有的情况
第一层循环：去重，当前循环四数之和的最小值:nums[first]+nums[first+1]+nums[first+2]+nums[first+3]和最大值:nums[first]+nums[length]+nums[length-1]+nums[length-2]+nums[length-3]分别与target比较，不符合情况，直接continue；
第二层循环：去重，设置第三个数的初始下标three=second+1，第四个数的初始下标four=length-1，
同样的把当前四数之和的最小值nums[first]+nums[second]+nums[second+1]+nums[second+2]和最大值：nums[first]+nums[second]+nums[length]+nums[length-1]与target比较，不符合情况，直接continue；
第三层循环：这一层循环就是移动three和four两个指针，遍历数组找出符合的组合；
sum=nums[first]+nums[second]+nums[three]+nums[four]
    1. sum > target: four--;
    2. sum < target: three++;\
    3. sum == target: 找到符合情况的组合，加入result；同时需要把three指针和four指针在移动过程中存在的重复值去除掉；
最终得到的result就是所有不重复的结果

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int length=nums.length;
        List<List<Integer>> result=new ArrayList<>();
        if(nums==null||length<4){
            return result;
        }
        Arrays.sort(nums);
        for(int first=0;first<length-3;first++){
            if(first>0&&nums[first]==nums[first-1]){
                continue;
            }
            int min=nums[first]+nums[first+1]+nums[first+2]+nums[first+3];
            if(min>target){
                break;
            }
            int max=nums[first]+nums[length-1]+nums[length-2]+nums[length-3];
            if(max<target){
                continue;
            }

            for(int second=first+1;second<length-2;second++){
                if(second>first+1&&nums[second]==nums[second-1]){
                    continue;
                }
                int three=second+1;
                int four=length-1;
                int min1=nums[first]+nums[second]+nums[three]+nums[three+1];
                if(min>target){
                    continue;
                }
                int max1=nums[first]+nums[second]+nums[four]+nums[four-1];
                if(max1<target){
                    continue;
                }
                while(three<four){
                    int current=nums[first]+nums[second]+nums[three]+nums[four];
                    if(current<target){
                        three++;
                    }else if(current>target){
                        four--;
                    }else{
                        result.add(Arrays.asList(nums[first],nums[second],nums[three],nums[four]));
                        three++;
                        while(three<four&&nums[three]==nums[three-1]){
                            three++;
                        }
                        four--;
                        while(three<four&&second<four&&nums[four]==nums[four+1]){
                            four--;
                        }
                    }
                }
            }
        }
        return result;
    }
}
```