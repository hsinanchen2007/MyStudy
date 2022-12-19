刚开始想这样
var addTwoNumbers = function(l1, l2) {
        var arr1 = [];
        var arr2 = [];
        function add(arr,obj){
            arr.push(obj.val)
            if(obj.next){
                add(arr,obj.next)
            }
            return arr
        }
        arr1 = add(arr1,l1);
        arr2 = add(arr2,l2);
        var len1 = arr1.length;
        var len2 = arr2.length;
        var len =  len1 > len2 ? len1 : len2
        var sum1 = 0;
        var sum2 = 0;
        for(var i = 0; i < len; i++){
            if(arr1[i]){
                sum1 += arr1[i]*Math.pow(10,i);
            }if(arr2[i]){
                sum2 += arr2[i]*Math.pow(10,i);
            }
        }
        var sum = sum1 + sum2;
        sum = sum + '';
        return sum.split('').reverse();
    };
也就是把对象转化成数组来存储，会容易很多，但是输出总是undefined。于是只能下面来做

var addTwoNumbers = function(l1, l2) {
    var tempNode = new ListNode(0);
    var result = tempNode;
    var carry = 0;
    while(l1 || l2){
        var val1 = l1 ? l1.val : 0;
        var val2 = l2 ? l2.val : 0;
        var sum = val1 +val2 + carry;//sum只需要个位数，而且有可能需要
         carry = sum < 10 ? 0 : 1;
        tempNode.next = new ListNode(sum%10);
        tempNode= tempNode.next;
          if(l1)l1 = l1.next;
        if(l2)l2 = l2.next;
    }
      if (carry > 0){
        tempNode.next = new ListNode(carry);
    }
    return result.next
};