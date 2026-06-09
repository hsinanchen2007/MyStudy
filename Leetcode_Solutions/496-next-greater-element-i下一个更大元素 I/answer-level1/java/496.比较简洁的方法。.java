```
class Solution {
   	public int[] nextGreaterElement(int[] nums1, int[] nums2) {

		int[] res = new int[nums1.length]; //需要返回的数组res
		int x = 0; //数组res的下标
		for (int i : nums1) { //遍历nums1和nums2    
			for (int j = 0; j < nums2.length; j++) { 
				if (nums2[j] == i && j != nums2.length - 1) { //找到nums2和nums1相同元素的元素下标j，且j不在末尾
					int y = 1;  //初始化y用来在dowhile里推进j
					int z = -1; //初始化z用来标记nums2里有没有下一个更大的元素
					do {
						if (nums2[j + y] > i) { //判断是否是下一个更大的元素
							res[x++] = nums2[j + y]; 
							z = 1; //改一下标记
							break; 
						} else {                //不满足条件就推进j
							y++;
							continue;
						}

					} while (y + j < nums2.length); //循环到nums2的末尾
					if (z == -1) { //z如果保持不变，说明没有下一个更大元素
						res[x++] = -1;
					}

				}

				if (nums2[j] == i && j == nums2.length - 1) { //i在nums2的末尾，则必定为-1
					res[x++] = -1;
				}
			}
		}
		return res;

	}
}
```
