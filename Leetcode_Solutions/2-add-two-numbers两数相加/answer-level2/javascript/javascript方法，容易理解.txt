先转成数组相加再转为链表，顺带回顾一下力扣的数组相加题目
```
var addTwoNumbers = function(l1, l2) {
    if(!l1){
        return l2;
    }else if(!l2){
        return l1;
    }
    //将val值都提取出来放入数组
    var arr1=[],arr2=[];
    while(l1){
        arr1.push(l1.val);
        l1=l1.next;
    }
    while(l2){
        arr2.push(l2.val);
        l2=l2.next;
    }
    //两个数组相加
    var addArray=function(arr1,arr2){
        var jdg=false,newArr=[],sum=null,num=null,
            len=Math.max(arr1.length,arr2.length);
        for(i=0;i<len;i++){
            sum=(arr1[i]?arr1[i]:0)+(arr2[i]?arr2[i]:0)+(jdg?1:0);
            num=sum%10;
            jdg=(sum>=10);
            newArr.push(num);      
        }
        if(jdg){
            newArr.push(1);
        }
        return newArr;
    }
    //将返回的数字转成链表
    var result=addArray(arr1,arr2);
    var node={
        val:null,
        next:null
    },
        head=node;
    for(i=0;i<result.length;i++){
        node.next={
            val:result[i],
            next:null
        }
        node=node.next;
    }
    return head.next;  
};
```
