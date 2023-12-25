# Book-Finder-App
PROBLEM STATEMENT



Time is most precious, we don`t want that you waste your time to find a book from urdu bazar or another market
So, we make an application to save your time.

CHOOSED ELEMENTS OF DSA
STRUCTURE
CLASS
LINKLIST
STRINGS 
FILE HANDLING
FUNCTIONS
TIME FUNCTIONS
Window.h ‘s DELAY FUNCTIONS

ALGORITHM
START
MAIN ( )
Show CONTROL PANNEL()

print    “ Press 1 to Search book “
print    “ Press 2 to Find nearby store “
print    “ Press 3 to  find 4-Star or above rated books “
read choice

 if (choice ==1)
      then,
              print   “ Enter Book Name “
              read book name

if(Book Name == File Book)
        then,       
                    show relevant books
           then,
                     Read the name and further details to place order.

Show menu:
Print   “ press 1 to add filters ”
print   “ press 2 to buy books “
print   “ press 3 to search book “
Read choice again

	

if  (choice == 1)
then,     goto filters
print   “ press 1 to find books that's are nearest to your location “
print   “ press 2 to find lowest price books “ 
print   “ press 3 to top rated books “
Read choice again

if (choice == 1)
 then, 
      show nearest books

else if (choice == 2)
    then,  
             show books of lowest price
else if(choice ==3)
  then, 
           show top rated books

else 
       print   “ INVALID CHOICE “ 
else if (choice == 2 )
    then,
          call order function
          Read details from user end
     then, 
           confirm order
                   GET INVOICE .......

else if (choice == 3)
        then,      
                go back to search( ) 


else 
print  “ Book is not available “
Return main menu
else if (choice == 2)
    then, 
           goto  near by store ( )
           Print   “ Enter Location “
           Read  Location
           Show results for location
if (loc <= 500 )
then, 
   show results  for location

else if (loc > 500 )
then,
  show results for this location

else 
print DISTANCE ..........

else if (choice == 3)
then,    
    show top rated books from search
    Read rate

	if( rating >= rate )
	then,  
	    show books
else 
print Not available in this rating 
else 
print   “ INVALID CHOICE “

STOP




