////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  [projectName]
//  File:     PrintableCoordinatewise.h (print)
//  Authors:  Ofer Dekel
//
//  [copyright]
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PrintableLayer.h"
#include "LayerLayout.h"

// layer
#include "Coordinatewise.h"

// stl
#include <iostream>

/// <summary> A printable coordinatewise. </summary>
struct PrintableCoordinatewise : public layers::Coordinatewise, public PrintableLayer
{
public:
    /// <summary> Gets a friendly layer name. </summary>
    ///
    /// <returns> The friendly layer name. </returns>
    virtual std::string GetFriendlyLayerName() const override;

    /// <summary> Returns the number of elements in the layer. </summary>
    ///
    /// <returns> The number of elements in the layer. </returns>
    virtual uint64 Size() const override;

    /// <summary> Assignment operator from Coordinatewise. </summary>
    ///
    /// <param name="coordinatewise"> The coordinatewise layer to assign from.</param>
    void operator=(const layers::Coordinatewise& coordinatewise);

    /// <summary> Assignment operator from layer to PrintableLayer. </summary>
    ///
    /// <param name="layer"> The layer being copied. </param>
    virtual void operator=(const layers::Layer& layer) override;

    /// <summary> Prints a SVG description of the underlying class to an output stream. </summary>
    ///
    /// <param name="os"> [in,out] Stream to write data to. </param>
    /// <param name="left"> The left. </param>
    /// <param name="top"> The top. </param>
    /// <param name="layerIndex"> Zero-based index of the layer. </param>
    /// <param name="Arguments"> The arguments. </param>
    ///
    /// <returns> A LayerLayout. </returns>
    virtual LayerLayout Print(std::ostream& os, double left, double top, uint64 layerIndex, const PrintArguments& arguments) const override;

    /// <summary> Returns an iterator that enumerates the input coordinates for a specified element. </summary>
    ///
    /// <param name="index"> Zero-based element index. </param>
    ///
    /// <returns> The input coordinates. </returns>
    virtual layers::Layer::InputCoordinateIterator GetInputCoordinates(uint64 index) const override;
};
