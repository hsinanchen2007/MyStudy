就是统计两个1之间有几个0,然后加1
```
var binaryGap = function(N) {
   let bi= N.toString(2);
   let max=0;
   let arr= bi.match(/(?<=1)0*(?=1)/g);

    if (arr==null)
    return 0;   
    for(let i=0;i<arr.length;i++){
       if(arr[i].length+1>max)
           max=arr[i].length+1;     
    }
     return max;
};
```
