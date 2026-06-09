### 解题思路
执行用时 :
22 ms
, 在所有 java 提交中击败了
5.06%
的用户
内存消耗 :
36.9 MB
, 在所有 java 提交中击败了
43.47%
的用户

### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        //创建一个集合  
    	ArrayList<Integer> list1 = new ArrayList<>();  
        //遍历数组往集合里存元素  
        for(int i=0;i<nums1.length;i++){  
            //如果集合里面没有相同的元素才往里存  
            if(!list1.contains(nums1[i])){  
                list1.add(nums1[i]);  
            }  
        }  
        ArrayList<Integer> list2= new ArrayList<>(); 
        //遍历数组往集合里存元素  
        for(int i=0;i<nums2.length;i++){  
            //如果集合里面没有相同的元素才往里存  
            if(!list2.contains(nums2[i])){  
                list2.add(nums2[i]);  
            }  
        } 
        ArrayList<Integer> reslist=new ArrayList<>();
        for(int i=0;i<list1.size();i++) {
        	for(int j=0;j<list2.size();j++) {
            	if(list1.get(i).intValue()==list2.get(j).intValue()) {
            		reslist.add(new Integer(list1.get(i).intValue()));
            		break;
            	}
            }
        }
          
        //toArray()方法会返回一个包含集合所有元素的Object类型数组  
        int [] res=new int[reslist.size()];
        for(int i=0;i<reslist.size();i++) {
        	res[i]=reslist.get(i);
        }
		return res; 

    }
}
```