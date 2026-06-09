### 解题思路
此处撰写解题思路
一开始是想着两个有序的数组合并的话需要重新new一个数组
首先复制其中一个数组，然后循环一个一个检查另一个数组的值再第一个数组应该的位置
找到后插入，然后继续找下一个

思路二：发现测试用例可能都是顺序的，就是不会一个正序一个逆序，感觉这样的话只需要一个循环
两个指针，比较大小就可以了。

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
        var len1=nums1.length;
    var len2=nums2.length;
     var povit1=0;
    var povit2=0;
    var nums=[];
    var len=len1+len2;
    for(var i=0;i<len;i++){
    	var n1=nums1[povit1];
    	var n2=nums2[povit2];
    	if((povit1>=len1)&&(povit2<len2)){
    		nums.push(n2);
    		povit2++;
    	}else if((povit2>=len2)&&(povit1<len1)){
    		nums.push(n1);
    		povit1++;
    	}else if((povit1<len1)&&(povit2<len2)){
    		
    		if(n1<n2){
    		nums.push(n1);
    		povit1++;
    	}else{
    		nums.push(n2);
    		povit2++;

    	}
    	}
    }
    var mid=0;
    // var midIndex=0;
    if(len%2==0){
    	var midIndex1=len/2;
    	var midIndex2=len/2-1;
    	mid=(nums[midIndex1]+nums[midIndex2])/2;
    }else{
    	var midIndex=Math.floor(len/2);
    	mid=nums[midIndex];
    }
    return mid;
};
```