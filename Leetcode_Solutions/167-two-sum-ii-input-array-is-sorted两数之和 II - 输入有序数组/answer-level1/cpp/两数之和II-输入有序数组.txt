这题是经典的双指针解法,然后又因为是有序数组,所以选用一个指针left指向头部,一个指针right指向尾部
如果两个元素之和sum 比 target大 说明需要找两个更小的元素 所以将right-1,如果sum比target小说明需要找两个更大的元素
所以left+1，如果sum=target则说明这两个元素是我们要找的元素

适合用双指针的情形1 数组有序, 且需要从两端向中间移动

代码示例如下
vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> res;
        while( left < right ) {
            int sum = numbers[left] + numbers[right];
            if ( sum == target  ) {
                res.push_back( left + 1 );
                res.push_back( right + 1 );
            } else if ( sum > target ) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};