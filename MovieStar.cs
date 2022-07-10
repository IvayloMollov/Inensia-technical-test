using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_Task1
{
    class MovieStar{
        private string name;
        private string gender;
        private string nationality;
        private int age;

        public string Name{
            get { return name; }
            set { name = value != null ? value : ""; }
        }

        public string Gender{
            get { return gender; }
            set { gender = value != null ? value : "undefined"; }
        }

        public string Nationality{
            get { return nationality; }
            set { nationality = value != null ? value : "unknown"; }
        }

        public int Age{
            get { return age; }
            set { age = value > 0 ? value : 0; }
        }
        public MovieStar(){
            Name = "";
            Gender = "";
            Nationality = "";
            Age = 0;
        }
        public MovieStar(string name, 
                         string gender, 
                         string nationality, 
                         int age){
            Name = name;
            Gender = gender;
            Nationality = nationality;
            Age = age;
        }
        public MovieStar(MovieStar other){
            Name = other.name;
            Gender = other.gender;
            Nationality = other.nationality;
            Age = other.age;
        }
        public override string ToString()
        {
            return string.Format($"Name: {Name}\n"+
                $"Gender: {Gender}\n"+
                $"Nationality: {Nationality}\n" +
                $"Age: {Age} years old\n\n");
        }
    }
}
