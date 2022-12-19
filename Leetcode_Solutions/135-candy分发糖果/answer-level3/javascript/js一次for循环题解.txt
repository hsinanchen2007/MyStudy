var candy = function(ratings) {
    const len = ratings.length;
    const arr = new Array(ratings).fill().map(item => 0);
    for(let i=0;i< len;i++){
        if(!arr[i]){
            if(ratings[i]>ratings[i-1]){
                arr[i] = arr[i-1]+1;
            } else{
                arr[i] =1;
                let j = i;
                while(j>-1 && ratings[j-1] > ratings[j] && arr[j] >=arr[j-1]){
                    arr[j-1]++;
                    j --;
                }
            }
        }
    }
    return arr.reduce((a,b)=>a+b)
};
一次for循环，每次while查找之前的数字