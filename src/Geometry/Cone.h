#ifndef _Geometry_Cone_H
#define _Geometry_Cone_H

#include <Geometry/Geometry.h>

namespace Geometry
{
	/** \brief Représentation d'un cone */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \class	Cone
	///
	/// \brief	A cone, centered in (0,0,0), 1.0 height, 1.0 base radius.
	///
	/// \author	F. Lamarche, Université de Rennes 1
	/// \date	04/12/2013
	////////////////////////////////////////////////////////////////////////////////////////////////////
	class Cone : public Geometry
	{
	public:

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \fn	Cone::Cone(int nbDiv, Material * material)
		///
		/// \brief	Constructor.
		///
		/// \author	F. Lamarche, Université de Rennes 1
		/// \date	04/12/2013
		///
		/// \param	nbDiv   	Number of base circle subdivisions.
		/// \param	material	The material.
		////////////////////////////////////////////////////////////////////////////////////////////////////
		Cone(int nbDiv, Material * material)
		{
			int center = addVertex(Math::makeVector(0.0f, 0.0f, 0.5f)) ;
			Disk disk(nbDiv, material) ;
			disk.translate(Math::makeVector(0.0f, 0.0f, -0.5f)) ;
			for(int cpt=0 ; cpt<nbDiv ; cpt++)
			{
				addTriangle(disk.getVertices()[cpt], disk.getVertices()[(cpt+1)%nbDiv], getVertices()[center], material) ;
			}
			merge(disk) ;
			//Math::Vector3 * center = new Math::Vector3(0.0, 0.0, 0.5) ;
			//addVertex(center) ;
			//Disk disk(nbDiv, material) ;
			//disk.translate(Math::Vector3(0.0, 0.0, -0.5)) ;
			//for(int cpt=0 ; cpt<nbDiv ; cpt++)
			//{
			//	addTriangle(new Triangle(disk.getVertices()[cpt], disk.getVertices()[(cpt+1)%nbDiv], center, material)) ;
			//}
			//merge(&disk) ;
		}
	} ;
}

#endif