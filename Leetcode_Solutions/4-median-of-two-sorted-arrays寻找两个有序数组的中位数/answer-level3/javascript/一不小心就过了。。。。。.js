var findMedianSortedArrays = function(arrA, arrB) {
       if (arrA.length>arrB.length){
            let tmp = arrA;arrA = arrB;arrB =tmp;
        }
        let m = arrA.length;
        let n = arrB.length;

        if (m === 0){
            let mid = parseInt(n/2);
            if (n%2===0){
                return (arrB[mid]+arrB[mid-1])/2
            }else {
                return arrB[mid];
            }
        }
        let i = 0,j;
        while (i<=m){
             j = parseInt((m+n)/2)-i;
            if (arrB[j-1]>arrA[i]){
                i++;
            }else if (arrA[i-1]>arrB[j]){
               i--;
            }else {
                let maxLeft = 0,minRight = 0;
                if (i===0){
                    maxLeft = arrB[j-1];
                } else if (j===0){
                    maxLeft = arrA[i-1];
                } else{
                    maxLeft = Math.max(arrA[i-1],arrB[j-1]);
                }

                if (i===m){
                    minRight = arrB[j]
                }else if(j===n){
                    minRight = arrA[i]
                }else {
                    minRight = Math.min(arrA[i],arrB[j]);
                }

                if ((m+n)%2===1){
                    return minRight;
                }else {
                    return (minRight+maxLeft)/2
                }
            }
        }
};