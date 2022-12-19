### 解题思路
建立如下工具类A
A{
int index; 记录每个用户的下标
int contain;	记录每个用户的容量
}
使用List<A> 存储后按contain升序排序
从List中 按顺序 分组，
第一个用户[5 1] 下标为5，容量为1，则存自己即可；
第二个用户[0 3] 下标为3，容量为3，则存储 0 1 2 后面的连续三个；
以此类推，直到List 为空。
### 代码

```java
class Solution {
    public static List<List<Integer>> groupThePeople(int[] groupSizes) {
    class A{
	A(int i,int c){index = i;contain = c;}
	int index;
	int contain;
	public String toString(){
		return index+" "+contain;
	    }
    }
        
        List<A> list = new ArrayList<A>();
        for(int i=0;i<groupSizes.length;i++){
        	A a = new A(i,groupSizes[i]);
        	list.add(a);
        }
        
        Collections.sort(list,new Comparator<A>(){
        	public int compare(A a,A b){
        		if(a.contain==b.contain)
        			return 0;
        		else
        		return a.contain > b.contain ? 1:-1;
        	}
        });
        System.out.println(list.toString());
        List<List<Integer>> res = new ArrayList<>();
        while(list.size()>0){
        	List<Integer> temp = new ArrayList<>();
        	int len = list.get(0).contain;
        	for(int i=0;i<len&&i<list.size();i++){
        		temp.add(list.get(i).index);
        	}
        	res.add(temp);
        	while(len-->0)
        		list.remove(0);
        }
        System.out.println(res.toString());
        return res;
	}
}
```