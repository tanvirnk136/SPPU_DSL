def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1
    
def quick_sort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quick_sort(array, low, pi - 1)
        quick_sort(array, pi + 1, high)

def main():
    list1=[]
    while True:
        print("\t1.Input FE Percentages")
        print("\t2.Quicksort the array")
        print("\t3.Display top five scores")
        print("\t4.Exit")
        x=int(input("Enter your choice:"))

        if(x==1):
            n=int(input("\nEnter the length of array:"))
            print("\nEnter", n, "floating point percentages:")
            for i in range(n):
                y=float(input())
                list1.append(y)
            print("Percentages input successful!")

        elif(x==2):
            if(len(list1)==0):
                print("First input an array.")
            else:
                quick_sort(list1,0,n-1)
                print("Sorted scores: ", list1)
        
        elif(x==3):
            if(len(list1)==0):
                print("Percentages Array is empty")
         
            else:
                list1.reverse()
                for j in range(5):
                  print(j+1,"place score: ",list1[j])

        elif(x==4):
            quit()

        else:
            print("Wrong choice!")

main()
