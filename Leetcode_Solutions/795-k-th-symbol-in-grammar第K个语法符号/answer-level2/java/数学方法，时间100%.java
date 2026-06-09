求第K个字符跟多少行没关系，先看图片
![1.png](https://pic.leetcode-cn.com/9c51f7c79d8a2a2441f2f1895d7a6a86787dab78e00cba8f2814a34a841afe90-1.png)
我们要求第100个字符，128个字母，前64个不变，后64个就是前64个取反
所以第100个就是第36（100-64）个取反，
第36个就是第4（36-32）个取反
第4个就是第2（4-2）个取反
第2个就是第1（2-1）个取反
所以第n个就是  **第n个减去比n小的最大的2的整数次幂** 的那个字符取反就可以了
记录一下取反的次数，最后对二取余就可以了
代码如下：
```
class Solution {
    public int kthGrammar(int n, int k) {
		int a=1;int i=0;
		for(;;){
			if(a>=k){
				n=i;
				break;
			}else{
				a*=2;
				i++;
			}
		}
		i=0;
		while(k>1){
			if(k<=a) {a/=2;continue;}
			k-=a;
			i++;
		}
		return i%2;
    }
}
```


