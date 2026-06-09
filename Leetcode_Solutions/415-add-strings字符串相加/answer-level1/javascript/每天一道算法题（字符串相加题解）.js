题解：
思路1：双指针法

通过两个字符串的索引，逐一递减，如遇进一存在temp中，如遇短的字符串无值的时候，用0补位；需要注意的是最后的判断条件，如果最后需要进一则特殊处理；

执行用时：104ms；内存消耗：36.8MB；

```
var addStrings = function(num1, num2) {

    let i=num1.length-1;

    let j=num2.length-1;

    let arr=[];

    let temp=0;

    while(i>=0||j>=0){

           const n1=num1[i]-0||0;

           const n2=num2[j]-0||0;

           const num=n1+n2+temp;

           temp=num/10>=1?1:0;

           arr.push(num%10)

           i--; j--;

           if(i<0&&j<0&&temp)arr.push(1);

          }

    return arr.reverse().join('')

};
```

思路2：取长补短法

找到长的哪一个字符串，把短的字符串，用0填充，然后循环相加，判断是否进一；特殊处理。

执行用时：104ms；内存消耗：36.8MB；

```
var addStrings = function(num1, num2) {

    let maxLen=Math.max(num1.length,num2.length);

    let minLen=Math.min(num1.length,num2.length)

    if(num1.length!=maxLen){

        num1=(Array(maxLen-minLen).fill(0).join(''))+num1

    }else{

        num2=(Array(maxLen-minLen).fill(0).join(''))+num2

    }

    let arr=Array(maxLen).fill(0);

    for(let i=maxLen-1;i>=0;i--){

        let num=Number(num1[i])+Number(num2[i]);

        arr[i]=arr[i]>0?arr[i]+num:num;

        if(i==0&&arr[i]>9){

            arr[0]=arr[i]-10

            arr.unshift(1)

        }

        if(i>0&&arr[i]>9){

            arr[i]=arr[i]-10

            arr[i-1]=1

        }

    }

    return arr.join('')

};
```

关注公众号 惊天码盗  回复算法 参加每天一道算法题

