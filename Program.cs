using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
namespace Csharp_Task1
{
    class Program
    {   
        static void Main(string[] args)
        {
            decimal taxation(decimal grossSalary)
            {
                if (grossSalary <= 1000)
                {
                    return grossSalary;
                } else if (grossSalary > 1000 && grossSalary <= 3000)
                {
                    return (decimal)((double)(grossSalary - 1000) * 0.75 + 1000);
                }
                else
                {
                    return (decimal)((double)(grossSalary - 1000) * 0.9 + 700);
                }
                //the simplest way to add further taxes it via additional if() conditions 
            }
            Console.WriteLine(taxation(3400));
            string fileName = @"C:\Users\Ivo\Desktop\Inensia\IOfile.txt";
            MovieStar ivo = new MovieStar("ivo", "male", "bg", 22);
            List<MovieStar> movieStars = new List<MovieStar> 
            {
                ivo,
                new MovieStar("pesho","female","bg",29)
            };
            string json = JsonConvert.SerializeObject(movieStars);
            Console.WriteLine(json+"\n");
            if(System.IO.File.Exists(fileName) == false)
            {
                System.IO.File.WriteAllText(fileName, json);
            }
            else
            {
                System.IO.File.Delete(fileName);
                System.IO.File.WriteAllText(fileName, json);
            }
            List<MovieStar> newStars = JsonConvert.DeserializeObject<List<MovieStar>>(json);
            foreach (var item in newStars)
            {
                Console.WriteLine(item);
            }
        }
    }
}
