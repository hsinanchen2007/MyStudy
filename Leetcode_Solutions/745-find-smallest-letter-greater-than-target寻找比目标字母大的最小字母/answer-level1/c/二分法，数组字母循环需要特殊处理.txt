1、有序数组，且数组里的字母顺序是循环的，意味着可能在这个数组中z可能是第一个字母，所以首先先将此类数组重新规整为从小到大的数组
    int left = 0;
    int right = lettersSize - 1;
    while (letters[left] > letters[right]) {
        letters[left] -= 26;
        left++;              
    }
2、然后对target进行特殊情况调整，当target大于letter[right]时，将target - 26，消除字母循环带来的不便

3、使用二分法进行查询

特殊注意：所谓的有序数组中，可能会存在相同的元素


看了下大多数的题解代码中，都没有考虑数组循环这个场景