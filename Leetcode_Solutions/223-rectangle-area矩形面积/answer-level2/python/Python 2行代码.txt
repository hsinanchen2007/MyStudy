class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
    
        if B>=H or D<=F or A>=G or C<=E:return (C-A)*(D-B) + (G-E)*(H-F)
        return (C-A)*(D-B) + (G-E)*(H-F) - (min(C,G)-max(A,E))*(min(D,H)-max(B,F))