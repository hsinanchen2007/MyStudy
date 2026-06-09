
解法1：暴力求解
每次迭代到新的滑动窗口时，进行k次大小的遍历，逐次获取滑动窗口的最大值


    int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
        if (numsSize == 0) {
            *returnSize = 0;
            int tmp[0];
            return tmp;
        }

        int *data  = (int *)malloc(sizeof(int) * (numsSize-k+1));
        int i,j,max,index=-1;
        for (i=0; i<numsSize-k+1; i++) {
            max = nums[i];
            for (j=1; j<k; j++) {
                if (nums[i+j] > max) {
                    max = nums[i+j];
                }
            }
            data[++index] = max;
        }

        *returnSize = index + 1;
        return data;
    }


解法2：选择性双重循环
和解法1相比，减少了遍历滑动窗口获取最大值的次数。<br />
循环处理时，若即将抛弃的元素比最大值小，说明最大值仍在滑动窗口内，那么只需要将最大值与新元素进行比较即可得出新的最大值；若抛弃元素与最大值相同，那么加入的新元素的滑动窗口进行一次循环找出最大值。

    int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
        if (numsSize == 0) {
            *returnSize = 0;
            int tmp[0];
            return tmp;
        }


        int *response  = (int *)malloc(sizeof(int) * (numsSize-k+1));
        int i,j,max,index=-1;

        for (i=0; i<numsSize-k+1; i++) {
            if (i > 0 && nums[i-1] < max) {
                if (nums[i+k-1] > max) {
                    max = nums[i+k-1];
                }
            } else {
                max = nums[i];
                for (j=1; j<k; j++) {
                    if (nums[i+j] > max) {
                        max = nums[i+j];
                    }
                }
            }
            response[++index] = max;
        }

        *returnSize = index + 1;
        return response;
    }

解法3：双向队列求解（一种未想到的方式，PHP求解）<br />
思考点：
<br />1、插入一个新元素的时候，如何删去双向队列内比新元素小的数据；
<br />2、队列内的元素数量经常会比k小，那么滑动窗口前进时，如何剔除离开滑动窗口元素。

第一：如1,5，添加4，需要删除1。方法是判断将左侧元素与新元素进行判断，若左侧元素较小，则取出忽略并新增元素；若左侧元素较大，则只做新增处理。每次新元素都会做以上判断，所以可以保证每个元素都比右侧元素小，所以每次新增只需要判断一个即可。

第二：如果队列中仅存一个5，如何得知这个5何时从滑动窗口中丢弃。所以队列中存储元素在数组中的下标，而不是元素值，这样就可以根据当前迭代的i值大小来判断是否已超出窗口范围进行剔除。

    class Solution {

        /**
        * @param Integer[] $nums
        * @param Integer $k
        * @return Integer[]
        */
        function maxSlidingWindow($nums, $k) {
            if (count($nums) == 0) {
                return [];
            }

            $data = [];
            $queue = [];
            $length = count($nums);
            for ($i=0; $i<$length; $i++) {
                if ($i >= $k && $queue[count($queue) - 1] == $i - $k) {
                    array_pop($queue);
                }

                while (count($queue) > 0) {
                    $tmp = array_shift($queue);
                    if ($nums[$i] <= $nums[$tmp]) {
                        array_unshift($queue, $tmp);
                        break;
                    }
                }

                array_unshift($queue, $i);

                if ($i >= $k-1) {
                    $data[] = $nums[$queue[count($queue) - 1]];
                }
            }
            return $data;
        }
    }
