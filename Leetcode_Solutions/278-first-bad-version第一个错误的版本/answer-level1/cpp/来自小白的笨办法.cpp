定义 long long int 不用考虑整数溢出的问题，详情看代码     
思路： 利用二分查找思想判断：1.况如果一个版本是坏就去判断它的前一个版本是好的，如果是好的那么它就是第一个坏的版本， 如果它的前一个是坏的，那么向左找；2. 如果一个版本是好的，直接向右找。     
C++ 版代码：    

```angelscript
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // 定义 long long int 不用考虑整数溢出的问题
        long long int left = 1,right = n,medium=0;
    	bool result;
        // 迭代实现二分搜索
        while(left <= right){
        	medium = (left+right)/2;
        	result = isBadVersion(medium);     // 判断 medium 的好坏
        	if( result == false){              // 如果一个版本是好的，直接向右找。 
        		left = medium + 1; 
            //如果一个版本是坏就去判断它的前一个版本是好的，如果是好的那么它就是第一个坏的版本，
			}else if( result == true && isBadVersion(medium- 1) == false   ){
				break;                         // 结束查找    
			}else{
                //如果它的前一个是坏的，那么向左找；
				right = medium - 1; 
			}
		} 
		return  medium;                       //返回结果,它自动转换为 int 型
        // return  (int)medium;   强制转换一下也可以
    }
};
```
Java版代码：
  
```angelscript
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
      		// 定义 long  不用考虑整数溢出的问题
	    long  left = 1L,right = n;
	    int medium=0;
    	boolean result;
        while(left <= right){
        	// 计算用 long, 计算好之后强制类型转换为 int
        	medium = (int)((left+right)/2);
        	 // 判断 medium 的好坏
        	result = isBadVersion(medium);
        	if( result == false){
        		left = medium + 1;           // 如果一个版本是好的，直接向右找。
        		//如果一个版本是坏就去判断它的前一个版本是好的，如果是好的那么它就是第一个坏的版本，
			}else if( result == true && isBadVersion(medium- 1) == false   ){
				break;  	// 结束查找		    
			}else{
				 //如果它的前一个是坏的，那么向左找；
				right = medium - 1; 
			}
		} 
		return  medium;
    }
}
```

