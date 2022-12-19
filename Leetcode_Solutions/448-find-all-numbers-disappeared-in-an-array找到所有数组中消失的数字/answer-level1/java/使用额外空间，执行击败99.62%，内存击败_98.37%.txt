思路：
(1)用一个新数组实现对原数组的排序以及各数字计数
(2)循环新数据，当某个下标对应的值为0时，说明该值缺失
public  List<Integer> findDisappearedNumbers(int[] nums) {
		List<Integer> list = new ArrayList<>();
		int[] test = new int[nums.length];
		for(int i =0;i<nums.length;i++) {
			test[nums[i]]++;
		}
		for(int i =0;i<nums.length;i++) {
			if(test[i] == 0) {
				list.add(i);
			}
		}
		
		return list;
        
    }