渣水平只能写出这种代码了QAQ
```
/**
 * @param {number[]} data
 * @return {boolean}
 */
var validUtf8 = function(data) {
  for(let i=0;i<data.length;){
    
    let s=data[i].toString(2); //转二进制字符串
    if(s.length<8){ //若s不足8位，要在前面补0
      for(let j=s.length;j<8;j++){
        s='0'+s;  
      }
    }
    
    //计算二进制前面几个1
    let n=0;
    let count=0;
    while(s[n++]!=0&&n<8){ 
      count++;  
    }
    
    //如果data下标i的首字符串有count个1，则最后一个位置的下标为i+count-1，必须小于data.length
    //如果字符大于4个字节，则为false; 示例中没有第一个数首字符串为10的情况，所以count不能为1
    if(i+count-1>=data.length || count>4 || count==1){ 
      return false;
    }
    
    if(count==0){ //如果二进制前面没有1,即开始位置为0，则直接跳过这个数
      i++;
    }
    
    //判断后续count-1个数的首字符串是否为'10'
    for(let j=i+1;j<i+count;j++){
      let s1=data[j].toString(2);
      if(s1.length<8){ //若s1不足8位，要在前面补0
        for(let j=s1.length;j<8;j++){
          s1='0'+s1;  
        }
      }
      if(s1[0]!='1'||s1[1]!='0'){ //后面count-1个数的首字符串不为'10'，返回false
        return false;
      }
    }
    
    i+=count; //计算完一组后，i直接加上count
  }
  
  return true;
};
```
