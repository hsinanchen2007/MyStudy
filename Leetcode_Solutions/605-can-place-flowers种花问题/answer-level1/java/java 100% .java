```
执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :38.8 MB, 在所有 java 提交中击败了94.13%的用户
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
    	int [] arr = new int[flowerbed.length + 2];
        /** 两边加0 */
        System.arraycopy(flowerbed, 0, arr, 1, flowerbed.length);
        int count = 0;
        /** 注意i < flowerbed.length + 1 */
        for (int i = 1; i < flowerbed.length + 1; i ++) {
        	if (arr[i - 1] == 0 && arr[i] == 0 && arr[i + 1] == 0) {
        		count ++;
        		i ++;
        	}
        	if (count >= n)
        		return true;
        }
        
        return false;
    }
}