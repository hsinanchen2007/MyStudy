
js来了js来了js来了，用魔方翻转的思想做的
function printMatrix(matrix)
{
    var m=matrix;
    var a=[];  
    let s=m.length;
      if (s === 0) return [];
      if (s === 1) return matrix[0];
    let c=m[0].length;
    for(let i=0;i<c;i++){      
        a.push(m[0][i]);
        if(i==(c-1)&&s!=1){
            m.splice(0, 1);
            var b=[];
             for(let t=0;t<c;t++){
                  b[t]=new Array(); 
               for(let j=0;j<s-1;j++){
                b[t][j]=m[j][c-t-1];
                }
            }            
            i=-1;
            m=b;            
            c=m[0].length;
            s=m.length;      
        }
    }
    return a;  
}