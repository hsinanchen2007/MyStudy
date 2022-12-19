### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {

		List<Integer> res = new ArrayList<Integer>();
		int slen = s.length();
		int plen = p.length();
		if(slen < plen)
			return res;
		Map<Character,Integer> pmap = new HashMap<Character,Integer>();
		Map<Character,Integer> window = new HashMap<Character,Integer>();
		for (int i = 0; i < plen; ++i)
			pmap.put(p.charAt(i), pmap.getOrDefault(p.charAt(i), 0)+1);
		int left = 0;
		int right = 0;
		int match = 0;
		while(right < slen)
		{
			char c1 = s.charAt(right);
			if(pmap.containsKey(c1))
			{
				window.put(c1, window.getOrDefault(c1, 0)+1);
				if((int)window.get(c1) == (int)pmap.get(c1))
					match++;
			}
			right++;
			while(match == pmap.size())
			{
				if(right-left == plen)
					res.add(left);
				char c2 = s.charAt(left);
				if(pmap.containsKey(c2))
				{
					window.put(c2,window.get(c2)-1);
					if((int)window.get(c2)<(int)pmap.get(c2))
						match--;
				}
				left++;
			}
		}
		return res;
	
    }
}
```
思路就不说了  用滑动窗口
但是这里遇到的坑主要是两个大数通过Integer包装类型对比的时候无法相等
这也就是为什么我的代码要将Integer强制转化成int来比较的原因
具体的例子如下
		hs1.put('c',100000);
		hs2.put('c',100000);
		if(hs1.get('c') == hs2.get('c'))
			System.out.println("success");
其实这里是不会输出success
具体的就会涉及到Integer包装类型的比较问题了 
Integer的内部实现是这样的
8 public static Integer valueOf(int i) {
 9         if(i >= -128 && i <= IntegerCache.high)
10             return IntegerCache.cache[i + 128];
11         else
12             return new Integer(i);
13     }
首先Integer在运行的时候缓存了一个数组，数组代表的长度为-128～+128 
因此当我们比较128以内的数的时候 Integer a = new Integer(125) 和 Integer a = new Integer(125) 其实返回的是同一个缓存在内存中的对象，他们的地址一样所以 a==b 返回true；反之，如果Integer a = new Integer(129) 和 Integer a = new Integer(129)进行比较，a==b就会返回false，由于这个时候都是新建了一个Integer对象，这两个对象在堆中的地址不同，所以就无法返回相等了 
所以在我们遇到大一点的数据的时候，采用map存储后取出比较就会出现问题 
典型的case就是
题目中s=“a*200ba*200” p = "a*200"
这个时候
if((int)window.get(c1) == (int)pmap.get(c1))
if((int)window.get(c2)<(int)pmap.get(c2))
这两处如果不加类型强制转换的话 就会无法判断相等以及大小
谨记 ！！！