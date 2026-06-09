改了好几次，最后长这样，看了别人可以不用数组突然感觉自己解题方法好一般
var convert = function(s, numRows) {
     if(numRows<2||s.length<3) return s
     let arr=[]
     for(let i=0;i<s.length;i++){
        let divide=numRows-1,
            position=i%(2*divide),
            index=position<=divide?position:2*divide-position
        arr[index]= arr[index]?arr[index]+s[i]:s[i]
     }
     return arr.join('')
};