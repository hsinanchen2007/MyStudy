public class Solution1124_1 {
	public static void main(String[] args) {
		// hours数组(测试)
		int[] hours = {9,8,6,7,1,3,8,6,12,16,13,14,9,4,6};
		System.out.println(hours.length);
		// 转换hours的值
		for (int i = 0; i < hours.length; i++) {
			if (hours[i]>8) {
				hours[i] = 1;
			}else {
				hours[i] = -1;
			}
		}
		// 测试hours数组
		for (int i : hours) {
			System.out.println(i);
		}
		System.out.println("----");
		
		// while循环
		// 控制变量声明初始化
		int count = 0;
		// 声明存放最大长度的数组
		int[] max = new int[hours.length];
		// 声明临时变量
		int total = 0;
		int temp = 0;
		while (count < hours.length) {
			// 临时变量
			int flag = 0;
			// 开始存放
			int[] is = new int[hours.length-count]; 
			for (int i = count; i < hours.length; i++) {
				for (int j = count; j <= i; j++) {
					temp = hours[j];
					total += temp;
				}
			
				
				// 存放
				is[flag] = total;
				total = 0;
				flag++;
			
				
			}
//			// is测试
//			for (int i : is) {
//				System.out.println(i);
//			}

			for (int i = 0; i < is.length; i++) {
				if (is[i] > 0) {	
					// max[count]值默认为0
					max[count] = i;
				}
			}
			count++;
//			// 清空is[i]的值
//			for (int i = 0; i < is.length; i++) {
//				is[i] = 0;
//			}
		

		}
		// 测试max
		for (int i : max) {
			System.out.println(i);
		}
		
	}
}