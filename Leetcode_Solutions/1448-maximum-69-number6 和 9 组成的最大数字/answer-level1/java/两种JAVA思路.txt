### 解题思路
只需要将从高位到低位遇到的第一个6换成9，就可以得到最大数字。

### 方法一
方法一是我想到的笨办法，从高到低入栈，然后依次拿出来，将遇到的第一个6换成9，即可。

### 代码

```java
import java.util.LinkedList;
class Solution {
    public int maximum69Number (int num) {
        LinkedList<Integer> arr= new LinkedList<Integer>();
		int temp=num;	
		while(temp>0) {
			arr.push(temp%10);
			temp=temp/10;		
		}
		int result=0;
		boolean flag=false;
		while(!arr.isEmpty()) {
			temp=arr.pop();
			if(temp==6 && flag==false) {
				temp=9;
				flag=true;
			}
			result=result*10+temp;
			
		}
		return result;

    }
}
```
### 方法二 
看了大佬的题解后，得到的办法。将数字转换为字符串（字符串在Java中不可改变，可以使用一个StringBuilder)，然后从前往后，替换遇到的第一个字符6，即可。
```java
import java.util.LinkedList;
class Solution {
    public int maximum69Number (int num) {
        StringBuilder temp=new StringBuilder(String.valueOf(num));
		
		for(int i=0;i<temp.length();i++) {
			if(temp.charAt(i)=='6') {
				temp.setCharAt(i, '9');
				break;
			}
		}
		num=Integer.parseInt(temp.toString());//将StringBuilder对象转换为String对象，再转换为整数
		return num;

    }
}
```