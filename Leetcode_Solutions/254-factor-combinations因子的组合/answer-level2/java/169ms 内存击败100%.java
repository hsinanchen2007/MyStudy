1. 代码中的几个关键部分   第一：所有的因子都是从2开始。
2. 第二：由题目可知，n的因子不能包括它本身，所以tmp的size必须大于1（等于1的时候只包含他本身，不符合要求），
3. 第三：为了剔除重复元素，新添加的元素必须大于等于tmp中的最后一个元素 例如当n=32的时候 tmp中 2 2 2 4 这个时候还差一个因子2 但是2不能添加进tmp，因为2小于tmp中的最后一个元素4.如果添加进去会和2 2 2 2 4这个集合一样。
```java []
public static List<List<Integer>> partition(int n) {
    	List<List<Integer>> list=new ArrayList<List<Integer>>();
    	List<Integer> tmp=new ArrayList<Integer>();
    	tracebace(n, list, tmp);
    	System.out.println(list.toString());
    	return list;
    }

	public static void tracebace(int n,List<List<Integer>> list,List<Integer>tmp) {
    
        if (n==1 && tmp.size()>1) {
			list.add(new ArrayList<Integer>(tmp));
			return;
		}
        for (int i = 2; i <=n; i++) {
			if (n%i==0 ) {
				if (tmp.size()==0 ||i>=tmp.get(tmp.size()-1)) {
				tmp.add(i);
				tracebace(n/i,  list, tmp);
				tmp.remove(tmp.size()-1);
				
				}
			}
		}
    }
```

