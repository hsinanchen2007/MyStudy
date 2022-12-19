var simplifyPath = function(path) {
    var arr =path.split('/');
    var stack = arr.filter(function(v,i){
        return v && v.trim();
    })
    var result =[];
    for(var i =0;i<stack.length;i++){
        if(stack[i]=='.'){
            
        }else if(stack[i]=='..'){
            result.pop();
        }else{
            result.push(stack[i]);
        }
    }
    return '/'+result.join('/')
};