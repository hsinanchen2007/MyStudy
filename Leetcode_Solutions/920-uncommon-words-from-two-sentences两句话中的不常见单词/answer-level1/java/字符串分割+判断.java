### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int count(String[] arr,String str) {
		int count=0;
		for(int i=0;i<arr.length;i++) {
			if(arr[i].equals(str)) {
				count++;
			}
		}
		return count;
	}
	public String[] uncommonFromSentences(String A, String B) {
		ArrayList<String> list = new ArrayList();
		
        String[] arr = A.split("\\ ");
        String[] brr = B.split("\\ ");
        for(int i=0;i<arr.length;i++) {
        	if(count(arr,arr[i])>1) {
        		continue;
        	}
        	int j=0;
        	for(j=0;j<brr.length;j++) {
        		if(arr[i].equals(brr[j])) {
        			break;
        		}
        	}
        	if(j==brr.length) {
        		list.add(arr[i]);
        	}
        }
        for(int i=0;i<brr.length;i++) {
        	if(count(brr,brr[i])>1) {
        		continue;
        	}
        	int j=0;
        	for(j=0;j<arr.length;j++) {
        		if(brr[i].equals(arr[j])) {
        			break;
        		}
        	}
        	if(j==arr.length) {
        		list.add(brr[i]);
        	}
        }
        String[] crr = new String[list.size()];
        for(int i=0;i<crr.length;i++) {
        	crr[i]=list.get(i);
        }
        return crr;
    }
}
```