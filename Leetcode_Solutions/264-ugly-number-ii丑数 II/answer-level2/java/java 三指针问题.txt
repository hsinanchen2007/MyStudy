本想通过最简单的遍历方式来寻找所有的丑数，一开始就看错了题目，以为最大的丑数不超过1690，想着借用丑数1的逻辑来判断丑数，直接超出了时间限制，最后通过三指针的动态规划解决了问题，主要是在每一步更新丑数之后大小的问题，即谁在前边谁在后边。```
```
 public int nthUglyNumber(int n) {
         List<Integer> a = new ArrayList<>();
	     int i2 = 0;
	     int i3 = 0;
	     int i5 = 0;
	     a.add(1);
	     for(int i=1; i<=n; i++) {
	    	 int tmp = Math.min(2*a.get(i2), Math.min(3*a.get(i3), 5*a.get(i5)));
	    	 a.add(tmp);
	    	 if(tmp == 2*a.get(i2))
	    		 i2++;
	    	 if(tmp == 3*a.get(i3))
	    		 i3++;
	    	 if(tmp == 5*a.get(i5))
	    		 i5++;
	     }
	    return a.get(n-1);
    }
```

