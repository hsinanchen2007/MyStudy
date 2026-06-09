var backspaceCompare = function(S, T) {
    let arrS = S.split(''),arrT = T.split('');
    let newS = gets(arrS).join(''),newT = gets(arrT).join('');
    function gets(arr){
        let newArr = [];
        for(var i = 0;i<arr.length;i++){
            if(arr[i] == '#'){
                if(i > 0){
                   newArr = newArr.splice(i-1,1)
                }
            }else{
                newArr.push(arr[i])
            }
        }
        return newArr
    }
    console.log(newS,newT)
    if(newS == newT){
        return true
    }else{
        return false
    }
};