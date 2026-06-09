```
/**
 * @param {number[][]} moves
 * @return {string}
 */
var tictactoe = function(moves) {
    var Asteps=[]
    var Astring = ''
    var Bsteps=[]
    var Bstring= ''
    var win = ['123','456','789','147','258','369','159','357']
    for(var i=0;i<moves.length;i++){
        if(i%2===0){
            Asteps.push(moves[i])
        }else{
            Bsteps.push(moves[i])
        }
    }
    Asteps.map(item=>{
        Astring+=movesToString(item)
    })
   
    var a = Astring.split('').sort().join('')
    Bsteps.map(item=>{
        Bstring+=movesToString(item)
    })
    var b = Bstring.split('').sort().join('')
    for(var i =0;i<win.length;i++){
        if(a.indexOf(win[i][0])!==-1&&a.indexOf(win[i][1])!==-1&&a.indexOf(win[i][2])!==-1){
            return "A"
        }
        if(b.indexOf(win[i][0])!==-1&&b.indexOf(win[i][1])!==-1&&b.indexOf(win[i][2])!==-1){
            return "B"
        }
    }
    if(moves.length>=9){
        return "Draw"
    }else {
        return "Pending"
    }
    
};

var movesToString = function(item){
        var dx =item[0]
        var dy = item[1]
        if(dx==0){
            return dy===0?'1':(dy===1?'2':'3')
        }
        if(dx==1){
            return dy===0?'4':(dy===1?'5':'6')
        }
        if(dx==2){
            return dy===0?'7':(dy===1?'8':'9')
        }
}
```
