### 解题思路
  我们需要对一组整数重新排序，使得能组成一个最大的整数。那什么样的顺序才能构造出最大整数呢？**要让整数越大，我们就要让越高位的数越大。** 
  因此我们就要按这个原则对数组进行重新排序，此时我们的比较依据并不是两个数的数值大小，而是这两个数中哪一个数的高位的数值越大。比如2和10，单纯从数值看，肯定是10大，但是如果把10放在前面，得到的是102，并不是最大数，因此我们要从高位逐位开始比较，2比1大，所以2放在最前面构造出的数才会越大，重新组合得到的最大数是210。
  明白了这个思路，就开始编写两数比较的代码了。因为我们需要从高位开始逐位比较，因此可以将数字转成字符串再比较。
  - 首先建立两个指针i和j，指向字符串a和b对应位置的字符，都初始为0。
  - 如果a[i]>b[j]，则说明a的高位数值比b大，返回true；
  - 如果a[i]<b[j]，则说明a的高位数值比b小，返回false；
  - 如果a[i]==b[j]，则同时将指针加一，往后移动，如果其中一个数已经移动到了末尾，则重新将指针置0。
```java
    /**
    * 若a>=b，返回true，否则返回false
    */
    boolean max(String sa,String sb) {
    	int i=0,j=0;
    	while(i<sa.length()&&j<sb.length()) {
    		char ca=sa.charAt(i);
			char cb=sb.charAt(j);
    		if(ca>cb)return true;
    		else if(ca<cb)return false;
    		else {
    			if(i+1==sa.length()&&j+1==sb.length())break;
    			if(i+1<sa.length())i++;
    			else i=0;
    			if(j+1<sb.length())j++;
    			else j=0;
    		}
    	}
    	return true;
    }
```
  两数的大小比较代码完成了，接下来找个排序算法替换掉其中的大小比较部分就OK了，具体排序算法就不赘述了。

```java

    public void quickSort(int[] arr,int low,int high){
        int i,j,temp,t;
        if(low>high){
            return;
        }
        i=low;
        j=high;
        temp = arr[low];
        while (i<j) {
            //--先看右边，依次往左递减
            while (!max(temp+"",arr[j]+"")&&i<j) {
                j--;
            }
            //--再看左边，依次往右递增
            while (max(temp+"",arr[i]+"")&&i<j) {
                i++;
            }
            //如果满足条件则交换
            if (i<j) {
                t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
            }
 
        }
        //最后将基准为与i和j相等位置的数字交换
         arr[low] = arr[i];
         arr[i] = temp;
        //递归调用左半数组
        quickSort(arr, low, j-1);
        //递归调用右半数组
        quickSort(arr, j+1, high);
    }
 
```
  排完序还有一个问题需要注意，就是要去除字符串前面的0，如0123。这个也不难，贴代码：
```java

    public String largestNumber(int[] nums) {
        quickSort(nums,0,nums.length-1);
        String s="";
        boolean zeroFlag=false;
        for (int i = nums.length-1; i >= 0; i--) {
            if(zeroFlag)
        	s+=nums[i];
            else if(nums[i]!=0) {
            	zeroFlag=true;
            	s+=nums[i];
            }else if(s.equals("")&&i==0)
            	s=0+"";
        }
        return s;
    }
```
