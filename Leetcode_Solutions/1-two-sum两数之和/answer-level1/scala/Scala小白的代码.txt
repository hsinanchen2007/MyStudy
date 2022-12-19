object Solution {
    def orangesRotting(grid: Array[Array[Int]]) :Int  = {
        var x : Int = 0
        var y : Int = 0
        var count : Int = 0
   
        var badOrange = Vector[Vector[Int]]()

        for { i <- 0 to (grid.length - 1 );
            j <- 0 to (grid(i).length - 1);
            if (grid(i)(j) == 2)}
               badOrange = badOrange :+ Vector(i,j)
        if (badOrange.length != 0)
            count = -1
        while(badOrange.length != 0) {
            var num_ora = badOrange.length
            while(num_ora != 0) {
                x = badOrange(0)(0)
                y = badOrange(0)(1)
               if ((x > 0 && grid(x -1)(y) == 1)) {
                    badOrange = badOrange :+ Vector(x - 1, y)
                    grid(x -1)(y) = 2
               }
               if ((x < (grid.length - 1) && grid(x + 1)(y) == 1)) {
                    badOrange = badOrange :+ Vector(x + 1,y)
                    grid(x + 1)(y) = 2
               }
               if ((y > 0 && grid(x)(y - 1) == 1)) {
                   badOrange = badOrange :+ Vector(x, y - 1)
                    grid(x)(y - 1) = 2
               }
               if ((y < (grid(x).length - 1) && grid(x)(y + 1) == 1)) {
                    badOrange = badOrange :+ Vector(x, y + 1)
                    grid(x)(y + 1) = 2
               }
                badOrange = badOrange.dropWhile(_ == badOrange.head)
                num_ora -= 1
            }
            count += 1
        } 
        for(args <- grid ; arg <- args) {
            if(arg == 1) 
                return -1
            }
        return count
    }
  
}
