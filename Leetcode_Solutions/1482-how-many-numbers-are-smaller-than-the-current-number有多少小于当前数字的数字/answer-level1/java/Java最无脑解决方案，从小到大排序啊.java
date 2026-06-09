### 解题思路

执行用时 :8 ms
内存消耗 :41.2 MB
首先这是一个很偷懒的解决办法，写的时候没考虑各种复杂度，欢迎评论区指点。
请统计数组中比某数小的数字数目，排序吧，Arrays.sort(sortArray);……
现在有了两个数组，一个是从小到大的sortArray，一个是原本顺序的nums。
遍历sortArray，每一个新遇到的不同项一定比它前面的大，所以比它小的个数就是其index了。
接下来返回结果就好了，为了可读性，还有个名为result的数组，遍历nums，对应result的位置，寻找在sortArray第一次匹配的相同的数，保存它在sortArray的index到result的正确位置。
恭喜，解题结束！

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] sortArray = nums.clone();
        Arrays.sort(sortArray);
        int[] result = new int[nums.length];
        for(int i=0; i<result.length; i++) {
            for(int j=0; j<sortArray.length; j++) {
                if(nums[i]==sortArray[j]) {
                    result[i]=j;
                    break;
                }
            }
        }
        return result;
    }
}
```