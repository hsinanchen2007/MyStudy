执行用时 :0 ms,
内存消耗 :38.2 MB。
class Solution {
    public int strStr(String haystack, String needle) {

      if (!haystack.contains(needle))
            return -1;
        // 双指针 其实就是利用两个指针构成一个区间段不断后移判断。
        int i = 0,j = needle.length();
        while (j < haystack.length()){
            if (haystack.substring(i,j).equals(needle))
                break;
            i++;
            j++;
        }
        return i;
    }
}