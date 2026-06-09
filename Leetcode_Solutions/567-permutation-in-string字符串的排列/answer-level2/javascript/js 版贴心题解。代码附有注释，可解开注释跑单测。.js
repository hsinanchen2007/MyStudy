var checkInclusion = function(s1, s2) {
    if (s1.length > s2.length) return false; 
    let memo1 = new Map();
    let memo2 = new Map();
    let memo1Ents;
	for (let i = 0; i < s1.length; i++) {
       let current =  (memo1.get(s1[i]) || 0) + 1;
		memo1.set(s1[i],current )
	}

    memo1Ents = [...memo1.entries()].sort().toString();
	for (let i = 0; i < s2.length; i++) {
        let current =  (memo2.get(s2[i]) || 0) + 1;
         // console.log('-----------第',i+1,'次--------------') 
		if(i<s1.length){
		    memo2.set(s2[i],current )
            // console.log('memo2:',memo2,'   str:',s2.substr(0,i+1),)
        }else {   
            // console.log('memo2:',memo2,'  上一次串：',s2.substr(i-s1.length-1,s1.length)) 
			memo2.set(s2[i],current );
            let order = ( memo2.get(s2[i-s1.length]) || 1) -1 ;
            if(order === 0 ) {
                memo2.delete(s2[i-s1.length])
            }else{
                memo2.set( s2[i-s1.length],order)
            }
            // console.log('memo2:',memo2,'  加：',s2[i],'   减：',s2[i-s1.length],'   当前串：',[...memo2.keys()])        
		}
        const memo2Ents = [...memo2.entries()].sort().toString() 
        if(memo2Ents === memo1Ents){
            return true
        }
	}
    
     
     return false

};