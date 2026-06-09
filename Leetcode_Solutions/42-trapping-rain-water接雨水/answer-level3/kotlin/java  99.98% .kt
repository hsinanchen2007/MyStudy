我也说不来这是什么方法，就是当时自己想的是跑两次，从头尾各一次来找比自己高的柱子。先从头开始，找到就加容量，然后从找到的这根柱子开始继续跑。不找到就说明他是最高的，从尾开始跑到这根柱子，就可以了，时间复杂度可能比O(N)多一点点
class Solution {
   public static  int trap(int[] height) {
        if (height == null || height.length < 3) {
			return 0;
		}
        int res = 0;
        int i = 0;
        for (; i < height.length && height[i] == 0; i++);
        if (i >= height.length - 2) {
        	return 0;
        }
        int j = 0;
        for (; i < height.length - 1;) {
			j = i + 1;
			int tmp = 0;
			while (j < height.length && height[j] < height[i]) {
				tmp += height[i] - height[j++];
			}
			if (j == height.length) {
				break;
			} else {
				i = j;
				res += tmp;
			}
		}
        if(j==height.length) {
        	j--;
        	int k;
        	for(;j>i;) {
        		k=j-1;
        		int tmp=0;
        		while(k>i&&height[k]<height[j]) {
        			tmp+=height[j]-height[k--];
        		}
        		j=k;
        		res+=tmp;
        	}
        }
        return res;
    }

}