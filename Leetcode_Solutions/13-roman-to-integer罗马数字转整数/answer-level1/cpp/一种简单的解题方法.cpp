### 解题思路
用了一个整型数组将罗马数组序列转换成了对应的阿拉伯数字序列
然后利用比较的思想 前一个数大于等于后面则加上 否则减去 最后一个数直接加上

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
         int result=0;
	//转换数字序列
     int*array=new int[s.length()];
     for(int i=0;i<s.length();i++){
     	switch (s[i]){
     		case 'I' : array[i]=1;
     		break;
     		case 'V' : array[i]=5;
     		break;
			case 'X' : array[i]=10;
     		break;
     		case 'L' : array[i]=50;
     		break;
     		case 'C' : array[i]=100;
     		break;
     		case 'D' : array[i]=500;
     		break;
     		case 'M' : array[i]=1000;
     		break;
		 }
	}
		//遍历比较
		 for(int i=0;i<s.length()-1;i++){
         if(array[i+1]<=array[i]){
             result+=array[i] ;
         }
         else{
         	result-=array[i];
		 }
		 
     }
		//最后一个数字直接加上
	 result+=array[s.length()-1];
       return result;
    }
};
```