
    var generate = function(numRows) {
        return digui(numRows,1,[])
    };
    let digui = (numRows,i,arr)=>{
        if(numRows>=i){
            arr.push(hanglde(i,arr))
            i++
            digui(numRows,i,arr)
        }
        return arr
    }

    let hanglde = (i,arr)=>{
        if(i == 1){
            return [1]
        }
        if(i == 2){
            return [1,1]
        }
        let newArr = []
        // console.log(arr)
        for(let x =0; x<i;x++){
            if(x==0 || i-1 == x){
                newArr.push(1);
                continue;
            }
            newArr.push( arr[i-2][x-1]+arr[i-2][x])
        }
        return newArr
    }