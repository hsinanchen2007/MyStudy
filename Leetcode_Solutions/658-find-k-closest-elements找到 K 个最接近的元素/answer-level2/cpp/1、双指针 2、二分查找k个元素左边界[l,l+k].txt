//方法1 双指针
/*
public class Solution {
 	public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> ret = Arrays.stream(arr).boxed().collect(Collectors.toList());
		int n = ret.size();
		if (x <= ret.get(0)) {
			return ret.subList(0, k);
		} else if (ret.get(n - 1) <= x) {
			return ret.subList(n - k, n);
		} else {
			int index = Collections.binarySearch(ret, x);
			if (index < 0)
				index = -index - 1;
			int low = Math.max(0, index - k - 1), high = Math.min(ret.size() - 1, index + k - 1);

			while (high - low > k - 1) {
				if ((x - ret.get(low)) <= (ret.get(high) - x))
					high--;
				else if ((x - ret.get(low)) > (ret.get(high) - x))
					low++;
				else
					System.out.println("unhandled case: " + low + " " + high);
			}
			return ret.subList(low, high + 1);
		}
	}
}

作者：LeetCode
链接：https://leetcode-cn.com/problems/find-k-closest-elements/solution/zhao-dao-kge-zui-jie-jin-de-yuan-su-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
//方法2 二分查找 k个元素的左边界，和 在两个有序数组以O（log（m+n））算法查找中位数类似；二分找到左边界之后，右边界即为左边界+k，非常巧妙
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        //二分查找 k个元素的左边界
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(x - arr[mid] > arr[mid + k] - x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + k + left); 
    }
};
