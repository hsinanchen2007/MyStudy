转数组就略过了，主要看过程哈~~
`var addTwoNumbers = function(l1, l2, unit=0, sum=0, carry=false) {
    /** 第一步转数组 **/
    var l1 = l1 instanceof Array ? l1 : [],
        l2 = l2 instanceof Array ? l2 : [];
    /** 检测到合并数组中没有元素后返回结果，结果一样转成链表 **/
    if(!l1.concat(l2).length) return sum; // 记得转链表
    unit = parseInt(l1[0] || 0) + parseInt(l2[0] || 0); // 个位相加
    carry && (unit += 1); // 进位标识符为true时进1位
    carry = false;
    if(unit>=10){ // 大于10保存个位，然后标识符追加true
        unit -= 10;
        carry = true;
    }
    sum = !sum ? unit+'' :  unit + sum;
    l1.splice(0,1);
    l2.splice(0,1);
    return addTwoNumbers(l1,l2,unit,sum,carry);
};`
不晓得够不够完善，有错误或者需要改进的地方希望大家指正
