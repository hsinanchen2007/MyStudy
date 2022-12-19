
class Solution {
    /**
     * @param Integer[] $candies
     * @return Integer
     */
    function distributeCandies($candies) {
        // 数组去重
        $count = array_unique($candies);
        // 判断去重数组的大小和原数组一半的大小
        if(count($count) >= count($candies)/2){
            return count($candies)/2;
        }else{
            return count($count);
        }
    }
}