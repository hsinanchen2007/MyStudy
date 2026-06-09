使用C语言提交的代码使用的是暴力法，并没有太大难度，代码如下：
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *a = (int *)malloc(sizeof(int) * 2);
    int i, j;
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                a[0] = i;
                a[1] = j;
                *returnSize = 2;
                return a;
            }
        }
    }               
    *returnSize = 0;
    return a;
}

使用java语言提交的代码使用了Map，用的思路还是暴力法，但是使用了Map建立映射，一开始定义空的Map，若存在，则输出两数，若不存在，则将映射存入Map，代码如下：
class Solution {
    public int[] twoSum(int[] nums, int target) {
        // 建立一个临时数组
        Map<Integer,Integer> tempArr=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            // 判断在数组tempArr中是否存在target - num[i]这个数
            if(tempArr.containsKey(target-nums[i])){
                // 若存在，则返回nums[i]这个数的下标，以及target - nums[i]这个键在tempArr中所对应的值
                return new int[]{tempArr.get(target-nums[i]),i};
            }else{
                // 若不存在，则将nums[i]这个数放入tempArr中
                tempArr.put(nums[i],i);
            }
        }
        throw new IllegalArgumentException("找不到想要的下标值");
    }
# 
C++和Python使用的思路也大致相同，C++使用的也是Map，Python则使用字典进行存储，代码如下：
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i in range(len(nums)):
            a = target - nums[i]
            if (a in dict):
                return dict[a],i
            else:
                dict[nums[i]] = i