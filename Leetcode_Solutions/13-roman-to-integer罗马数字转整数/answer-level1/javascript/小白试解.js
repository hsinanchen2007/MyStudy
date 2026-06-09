var romanToInt = function(s) {
    let num = 0;
    let arr = s.split('');
    for(let i=0;i<arr.length;){
        if(arr[i] == "I"){
            if(arr[i+1]=="V"){
               num += 4;
               i+=2;
           }else if(arr[i+1]=="X"){
               num += 9;
               i+=2;     
           }else{
               num +=1;
               i++;
           }
       }
        if(arr[i]=="V"){
              num += 5;
              i++;
       }
        if(arr[i]=="X"){
            if(arr[i+1]=="L"){
              num += 40;
              i+=2;  
           }else if(arr[i+1]=="C"){
              num += 90;
              i+=2;  
           }else{
              num += 10;
              i++; 
           }        
       }
        if(arr[i]=="L"){
              num += 50;
              i++;
       }
        if(arr[i]=="C"){
            if(arr[i+1]=="D"){
              num += 400;
              i+=2;  
           }else if(arr[i+1]=="M"){
              num += 900;
              i+=2;  
           }else{
              num += 100;
              i++; 
           }        
       }
        if(arr[i]=="D"){
              num += 500;
              i++;
       }
        if(arr[i]=="M"){
              num += 1000;
              i++;
       }
    }
    return num;
};