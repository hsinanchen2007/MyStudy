    看过之前三个数想加的小伙伴一定对双指针法不陌生了吧，没印象的去面壁！明明是前几道题（滑稽）。
    那么四个数跟三个数的区别在哪里呢，区别就在于再加一层循环就可以了嘛，看透了这一层，那么就好办了，
关键就在于如何判断重不重复，也就是去重的工作。有些限定条件和if还是while语句一定不能搞混，下面是我写的代码，
时间复杂度（O^3），大神写的（O^2）我没写出来，我这个大家凑活看看就好，有些注释我写在代码里面了
```
public static List<List<Integer>> fourSum(int[] nums, int target) {
		Arrays.sort(nums);//先排序
		List<List<Integer>> list=new ArrayList<>();
		for(int i=0;i<nums.length-2;i++){//这里面要记得i的范围，最多到倒数第三位，防止数组下标越界异常。
			int tem=target-nums[i];//先用target减掉nums[i]，这样剩下的问题就是三个数的双指针问题了。
			if(i>0&&nums[i]==nums[i-1])continue;//先让i走一遍，然后再开始判断重不重复。
			for(int j=i+1;j<nums.length-1;j++){//这里同样要注意y的取值范围。
				int L=j+1,R=nums.length-1;//设置双指针
				//if(j>1&&nums[j]==nums[j-1])continue;此处应该是j>i-1.
				if(j>i+1&&nums[j]==nums[j-1])continue;//判断y是不是重复
				while(L<R){
//					这里不能提前判断是不是重复，因为如果提前判断，如果数组里面数据全部为0的话，那么L就会一直加下去直到=R，
//                  程序最后什么都不返回。
//					if(nums[L]==nums[L+1]){
//						L++;
//						continue;
//					}
//					if(nums[R]==nums[R-1]){
//						R--;
//						continue;
//					}
					if(nums[j]+nums[L]+nums[R]==tem){
						list.add(Arrays.asList(nums[i],nums[j],nums[L],nums[R]));//利用Arrays的方法，省时简洁
						while(L<R&&nums[L]==nums[L+1])L++;//判断L是不是重复
						while(L<R&&nums[R]==nums[R-1])R--;//判断R是不是重复
//						    这里面又有错误，原来我写的是下面这两行代码，然后就报错了，最开始的错误是，有一个重复的返回数组，我想了半天，
//						不知道是哪里错了，后来看了看i和j的重复判断没有错误，所以排除了i和j，那就剩下里面的去重代码了，看了看，我用的是if
//						这就代表着只会判断一次，如果有是三个重复的数字的话，那么最后一个就很明显的重复了，所以if和while一定要区分好。
//						然后又去运行，结果又报错，错误是“Line 23: java.lang.ArrayIndexOutOfBoundsException: 4”
//						数组越界出错，什么原因呢，原因就是，没有加判定条件，加了之后终于能成功运行了。
//						if(nums[L]==nums[L+1])L++;
//						if(nums[R]==nums[R-1])R--;
						//我这里第一次错误的原因是，我在有了一个答案之后，我竟然没有进行R--和L++的操作，所以导致时间过长。内存溢出。真傻。
						L++;
						R--;
					}
					else if(nums[j]+nums[L]+nums[R]>tem){//如果结果偏大，就往左移。
						R--;
					}else if(nums[j]+nums[L]+nums[R]<tem){
						L++;
					}
				}
			}
		}return list;
	}
```
![2019-11-09_165815.jpg](https://pic.leetcode-cn.com/25a899fc1a950b7f898be78b12c97c121ba1dad77041f1256c353291d9d9c24c-2019-11-09_165815.jpg)

