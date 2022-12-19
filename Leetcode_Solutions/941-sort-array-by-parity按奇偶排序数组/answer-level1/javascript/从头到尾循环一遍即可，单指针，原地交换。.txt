不知跟双指针差异多大？

```

var sortArrayByParity = function(A) {
    var left = 0;
    var v;
    for(var i=0; i<A.length;i++){
        if((A[i] % 2) == 0){
            if(i>left){
                v = A[left];
                A[left] = A[i];
                A[i] = v;
            }
            left++;
        }
    }
    return A;
};

```