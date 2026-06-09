![image.png](https://pic.leetcode-cn.com/ad0a88b2d290f165b1f24fe3cbeb3f966a591f48264d50af69bda4eab5d1e236-image.png)


class Solution {
    public int hIndex(int[] citations) {
        return bi(citations, 0, citations.length-1);
    }
    private int bi(int[] a, int left, int right){
        int l = left; // 左边界，不动
        int r = right; // 右边界，不动
        int res = 0;
        while(l <= r){
            int mid = l + ((r-l)>>1);
            if(a[mid] >= right-mid+1){ // a[mid]~a[right]都大于等于right-mid+1
                    // h至少应该是right-mid+1，继续往左搜索，看是否h可以继续增大
                res = right-mid+1; // 保存每次的可能解，搜索最终的res就是题解
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return res;
    }
}